
local Players = game:GetService("Players")

Players.PlayerAdded : Connect(function(player)
	local leaderstats = Instance.new("Folder")
	leaderstats.Name = "leaderstats"
	leaderstats.Parent = player

	local boxes = Instance.new("IntValue")
	boxes.Name = "Boxes"
	boxes.Value = 0
	boxes.Parent = leaderstats
end)
