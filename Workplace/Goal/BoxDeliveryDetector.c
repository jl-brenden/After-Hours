local TruckGoal = script.Parent
local debounce = {}

TruckGoal.Touched:Connect(function(hit)
	if not hit:IsA("BasePart") then return end
	if hit.Name ~= "BoxCarry" then return end
	if debounce[hit] then return end
	debounce[hit] = true

	local owner = hit:FindFirstChild("Owner")
	if owner and owner.Value and owner.Value : IsA("Player") then
		local player = owner.Value
		local stats = player : FindFirstChild("leaderstats")
		if stats then
			local boxes = stats : FindFirstChild("Boxes")
			if boxes then
				boxes.Value += 1
			end
		end
	end
	
	hit : Destroy()
end)