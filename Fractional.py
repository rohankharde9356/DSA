def fractional_knapsack(weights, profits, capacity):
    parcels = sorted(
        zip(weights, profits),
        key=lambda item: item[1] / item[0],
        reverse=True
    )
    total_profit = 0
    selected = []

    for weight, profit in parcels:
        if capacity <= 0:
            break
        fraction = min(1, capacity / weight)
        selected.append((weight, profit, fraction))
        total_profit += profit * fraction
        capacity -= weight * fraction

    return total_profit, selected


n = int(input("Enter number of parcels: "))
weights, profits = [], []

for i in range(n):
    weights.append(float(input(f"Enter weight of parcel {i + 1}: ")))
    profits.append(float(input(f"Enter profit of parcel {i + 1}: ")))

capacity = float(input("Enter truck capacity: "))
max_profit, selected = fractional_knapsack(weights, profits, capacity)

print("\nSelected parcels:")
for weight, profit, fraction in selected:
    print(f"Weight: {weight}, Profit: {profit}, Taken: {fraction * 100:.2f}%")
print(f"\nMaximum Profit: {max_profit:.2f}")