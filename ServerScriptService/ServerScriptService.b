local DataStoreService = game:GetService("DataStoreService")
local PlayerBoxesStore = DataStoreService:GetDataStore("PlayerBoxesStore")


game.Players.PlayerAdded:Connect(function(player)	
	local leaderstats = Instance.new("Folder")
	leaderstats.Name = "leaderstats"
	leaderstats.Parent = player
	
	local boxes = Instance.new("IntValue")
	boxes.Name = "Boxes"
	boxes.Parent = leaderstats
	
end)
