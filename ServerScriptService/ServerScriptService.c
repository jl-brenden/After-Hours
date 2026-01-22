local DataStoreService = game:GetService("DataStoreService")
local ReplicatedStorage = game : GetService("ReplicatedStorage")
local Players = game : GetService("Players")

local PlayerBoxesStored = DataStoreService : GetDataStore("PlayerBoxes")

local BoxDeliveredEvent = Instance.new("RemoteEvent")
BoxDeliveredEvent.Name = "BoxDeliveredEvent"
BoxDeliveredEvent.Parent = ReplicatedStorage

Players.PlayerAdded:Connect(function(player)
    local leaderstats = Instance.new("Folder")
    leaderstats.Name = "leaderstats"
    leaderstats.Parent = player

    local boxes = Instance.new("IntValue")
    boxes.Name = "Boxes"
    boxes.Value = 0
    boxes.Parent = leaderstats
end)

BoxDeliveredEvent.OnServerEvent:Connect(function(player)
        if player and player:FindFirstChild("leaderstats") then
            local boxes = player.leaderstats : FindFirstChild("Boxes")
            if boxes then
                boxes.Value += 1
            end
        end
end)
