local function KICKOFF_DEF_POS(str)
	return function()
		local x, y
		x, y = CKickOffDefPos(str)
		return CGeoPoint:new_local(x,y)
	end
end

gPlayTable.CreatePlay{
firstState = "start",

["start"] = {
	switch = function ()
		if cond.isGameOn() then
			return "advance"
		end
	end,
	Leader   = task.marking("First"),
	Special  = task.marking("Second"),
	Assister = task.goSpeciPos(KICKOFF_DEF_POS("middle")),
	Middle   = task.rightBack(),
	Defender = task.leftBack(),
	Goalie   = task.goalie(),
	match    = "[ADMLS]"
},

["advance"] = {
	switch = function ()
		if  bufcnt(true, 90) then
			return "finish"
		end
	end,
	Special  = task.marking("First"),
	Assister = task.advance(),
	Leader   = task.marking("Second"),
	Middle   = task.rightBack(),
	Defender = task.leftBack(),
	Goalie   = task.goalie(),
	match    = "[ADMLS]"	
},


name = "Ref_KickOffDefV2",
applicable ={
	exp = "a",
	a = true
},
attribute = "attack",
timeout = 99999
}
