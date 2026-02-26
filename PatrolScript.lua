local PathfindingService = game:GetService("PathfindingService")

local npc = script.Parent
local humanoid = npc:WaitForChild("Humanoid")
local root = npc:WaitForChild("HumanoidRootPart")

local patrolFolder = workspace:WaitForChild("PatrolPoints")
local red = patrolFolder:WaitForChild("Red")
local blue = patrolFolder:WaitForChild("Blue")
local purple = patrolFolder:WaitForChild("Purple")

local patrolPoints = {red, blue, purple}
local currentIndex = 1

local function goToPoint(point)
    local path = PathfindingService:CreatePath({
        AgentRadius = 2,
        AgentHeight = 5,
        AgentCanJump = true
    })

    path:ComputeAsync(root.Position, point.Position)

    if path.Status == Enum.PathStatus.Success then
        local waypoints = path:GetWaypoints()
        for _, waypoint in ipairs(waypoints) do
            humanoid:MoveTo(waypoint.Position)
            humanoid.MoveToFinished:Wait()
        end
    else
        print("Couldn't find a path!")
    end
end

while true do
    local nextPoint = patrolPoints[currentIndex]
    goToPoint(nextPoint)

    currentIndex = currentIndex + 1
    if currentIndex > #patrolPoints then
        currentIndex = 1
    end

    wait(1)
end