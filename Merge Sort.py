def merge_sort(orders):
    if len(orders) <= 1:
        return orders

    mid = len(orders) // 2
    left = merge_sort(orders[:mid])
    right = merge_sort(orders[mid:])
    result = []

    while left and right:
        result.append(left.pop(0) if left[0][2] <= right[0][2]
                      else right.pop(0))

    return result + left + right


orders = []
while True:
    choice = input("\n1. Add order  2. Display orders  3. Sort orders  4. Exit\nChoice: ")

    if choice == "1":
        order_id = input("Order ID: ")
        item = input("Item name: ")
        minutes = int(input("Delivery time (minutes): "))
        orders.append((order_id, item, minutes))

    elif choice == "2":
        for order in orders:
            print(f"ID: {order[0]}, Item: {order[1]}, Delivery: {order[2]} min")

    elif choice == "3":
        orders = merge_sort(orders)
        print("Orders sorted by delivery time:")
        for order in orders:
            print(f"ID: {order[0]}, Item: {order[1]}, Delivery: {order[2]} min")

    elif choice == "4":
        break

    else:
        print("Invalid choice")