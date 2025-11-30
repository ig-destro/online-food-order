# online-food-order
Idea / Description

This is a food ordering system where:

A fixed menu of items is displayed (rolls , briyani, fries, etc.)

User can:

Select items by ID

Enter quantity

Order multiple items in one bill

System will:

Calculate subtotal

Add GST (5%)

Give discount if bill is large

Show final bill in proper format

Perfect for: arrays, structures, loops, functions.
S<img width="596" height="943" alt="Screenshot 2025-11-30 115736" src="https://github.com/user-attachments/assets/1d259d7b-41ce-4390-95a4-234511e055b8" />
 Algorithm (Step-by-step)

Start

Define a structure Item with:

id (int)

name (string)

price (float)


Create an array menu[] and initialize it with some fixed food items.

Display a welcome message and show the menu in table form.

Initialize:

subtotal = 0

Use a loop:

Ask user to enter item id (or 0 to finish)

If id == 0 → break loop

Ask for quantity

Search the menu[] array for the matching id

If found:

itemTotal = price * quantity

Add to subtotal

Optionally show “Item added to cart”

If not found:

Show “Invalid item id”

After the loop:

If subtotal == 0:

Print “No items ordered” and end

Else:

Calculate GST = 5% of subtotal

If subtotal >= 500, apply discount 10%

total = subtotal + gst - discount

Print final bill:


ubtotal

GST

Discount (if any)

Grand Total

End
