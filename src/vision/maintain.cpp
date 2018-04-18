#include "maintain.h"
#include "globaldata.h"
#include "staticparams.h"
#include "collisiondetect.h"
#include "visionmodule.h"
#include "field.h"
#include "dealball.h"
CMaintain::CMaintain()
{
    detectionBall= detectionFrame.mutable_balls();
//    for (int i=0;i<PARAM::ROBOTMAXID;i++){
//       // detectionRobot[PARAM::BLUE][i]=detectionFrame.add_robots_blue();
//       // detectionRobot[PARAM::YELLOW][i]=detectionFrame.add_robots_yellow();
//    }
}

void CMaintain::udpSocketConnect(){
    std::string addressStr = "127.0.0.1";
    zeus_port=23333;
    client_port=54320;
    groupAddress = QString(addressStr.c_str());
    udpSocket.bind(QHostAddress::AnyIPv4, zeus_port, QUdpSocket::ShareAddress);
    udpSocket.joinMulticastGroup(QHostAddress(groupAddress));
    client_udpSocket.bind(QHostAddress::AnyIPv4,client_port,QUdpSocket::ShareAddress);
    client_udpSocket.joinMulticastGroup(QHostAddress(groupAddress));
}

void CMaintain::udpSocketDisconnect(){
    udpSocket.abort();
    client_udpSocket.abort();
}

void CMaintain::init(){
    result.init();
    auto& state = GlobalData::instance()->immortalsVisionState;
    if (PARAM::USE_IMMORTAL_BALL){
        if(state.has_ball && Field::inChosenArea(state.ball.Position.X,state.ball.Position.Y))
            result.addBall(state.ball.Position.X,state.ball.Position.Y);
    }
    else{
        //Dealball::instance()->filteBall(result);
//        for (int i=0;i<GlobalData::instance()->processBall[0].ballSize;i++)
//            result.addBall(GlobalData::instance()->processBall[0].ball[i]);

        result.addBall(GlobalData::instance()->processBall[0].ball[0]);

    }
    for (int i=0;i<GlobalData::instance()->processRobot[0].robotSize[PARAM::BLUE];i++)
        result.addRobot(PARAM::BLUE,GlobalData::instance()->processRobot[0].robot[PARAM::BLUE][i]);
    for (int i=0;i<GlobalData::instance()->processRobot[0].robotSize[PARAM::YELLOW];i++)
        result.addRobot(PARAM::YELLOW,GlobalData::instance()->processRobot[0].robot[PARAM::YELLOW][i]);
    GlobalData::instance()->maintain.push(result);

    //udp start
    if (result.ballSize>0){
        detectionBall->set_x(result.ball[0].pos.x());
        detectionBall->set_y(result.ball[0].pos.y());
        if (PARAM::USE_IMMORTAL_BALL){
            double ballspeed= sqrt(state.ball.velocity.x*state.ball.velocity.x+state.ball.velocity.y*state.ball.velocity.y);
            detectionBall->set_speed(ballspeed);
            if (ballspeed > 7500) qDebug()<<"now BALL speed="<<ballspeed<<"mm/s";
        }
        else{
            detectionBall->set_speed(0);//todo
        }
    }
    else
    {
        detectionBall->set_x(-32767);
        detectionBall->set_y(-32767);
        detectionBall->set_speed(0);//todo
    }
    for (int i=0;i<result.robotSize[PARAM::BLUE];i++){
        detectionRobot[PARAM::BLUE][i]=detectionFrame.add_robots_blue();
        detectionRobot[PARAM::BLUE][i]->set_x(result.robot[PARAM::BLUE][i].pos.x());
        detectionRobot[PARAM::BLUE][i]->set_y(result.robot[PARAM::BLUE][i].pos.y());
        detectionRobot[PARAM::BLUE][i]->set_orientation(result.robot[PARAM::BLUE][i].angel);
        detectionRobot[PARAM::BLUE][i]->set_robot_id(result.robot[PARAM::BLUE][i].id);
        detectionRobot[PARAM::BLUE][i]->set_confidence(1);
        detectionRobot[PARAM::BLUE][i]->set_speed(0);//todo
    }
    for (int i=0;i<result.robotSize[PARAM::YELLOW];i++){
        detectionRobot[PARAM::YELLOW][i]=detectionFrame.add_robots_yellow();
        detectionRobot[PARAM::YELLOW][i]->set_x(result.robot[PARAM::YELLOW][i].pos.x());
        detectionRobot[PARAM::YELLOW][i]->set_y(result.robot[PARAM::YELLOW][i].pos.y());
        detectionRobot[PARAM::YELLOW][i]->set_orientation(result.robot[PARAM::YELLOW][i].angel);
        detectionRobot[PARAM::YELLOW][i]->set_robot_id(result.robot[PARAM::YELLOW][i].id);
        detectionRobot[PARAM::YELLOW][i]->set_confidence(1);
        detectionRobot[PARAM::YELLOW][i]->set_speed(0);//todo
    }
    int size = detectionFrame.ByteSize();
    QByteArray buffer(size,0);
    detectionFrame.SerializeToArray(buffer.data(),buffer.size());
    udpSocket.writeDatagram(buffer.data(),buffer.size(),groupAddress,zeus_port+1);
    client_udpSocket.writeDatagram(buffer.data(),buffer.size(),groupAddress,client_port+1);
    detectionFrame.clear_robots_blue();
    detectionFrame.clear_robots_yellow();
}

void CMaintain::run(bool sw){
    if (sw){
        init();
        CollisionDetect::instance()->visionAlart();

    }
    else{

    }
}
