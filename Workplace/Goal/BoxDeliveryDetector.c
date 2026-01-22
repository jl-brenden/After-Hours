local ReplicatedStorage = game:GetService("ReplicatedStorage")
local Players = game : GetService("Players")
local BoxDeliveredEvent = ReplicatedStorage : WaitForChild("BoxDeliveredEvent")

local goalPart = script.Parent

goalPart.Touched : Connect(function(hit)
    local player = Players:GetPlayerFromCharacter(hit.Parent)
    if player then
        BoxDeliveredEvent : FireServer(player)
        hit : Destroy()
    end
end)
