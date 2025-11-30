#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

struct Item {
    int id;
    char name[30];
    float price;
};

// Function prototypes
void showMenu(struct Item menu[], int n);
struct Item* findItemById(struct Item menu[], int n, int id);

// Function to display the menu
void showMenu(struct Item menu[], int n) {
    int i;
    printf("Available Menu:\n");
    printf("-------------------------------------------------\n");
    printf("ID\tItem Name\t\t\tPrice (Rs.)\n");
    printf("-------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%-20s\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to find item by ID
struct Item* findItemById(struct Item menu[], int n, int id) {
    int i;
    for (i = 0; i < n; i++) {
        if (menu[i].id == id) {
            return &menu[i];
        }
    }
    return NULL;
}
int main() {
    struct Item menu[MAX_ITEMS] = {
        {1, "Paneer Briyani",  199.0},
        {2, "Paneer Chilli",    99.0},
        {3, "Veg Momos",        89.0},
        {4, "French Fries",     79.0},
        {5, "Veggie Pizza",    159.0},
        {6, "Cold Coffee",      69.0},
        {7, "P.Noddles",       129.0},
        {8, "Paneer Roll",      119.0}
    };
    int n = 8;   // number of menu items

    int choiceId, quantity;
    float subtotal = 0.0, gst, discount = 0.0, total;
    char more;

    printf("         ONLINE FOOD ORDERING SYSTEM         \n");
    
    showMenu(menu, n);

    printf("\nStart placing your order.\n");

    while (1) {
        printf("\nEnter Item ID to order (0 to finish): ");
        scanf("%d", &choiceId);

        if (choiceId == 0) {
            break; // finish ordering
        }

        struct Item *selected = findItemById(menu, n, choiceId);
        if (selected == NULL) {
            printf("Invalid Item ID! Please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", selected->name);
        scanf("%d", &quantity);

        if (quantity <= 0) {
            printf("Invalid quantity! Skipping item.\n");
            continue;
        }

        float itemTotal = selected->price * quantity;
        subtotal += itemTotal;

        printf("Added: %d x %s = %.2f\n", quantity, selected->name, itemTotal);
        printf("Current Subtotal: %.2f\n", subtotal);
    }

    printf("                  FINAL BILL                 \n");
   

    if (subtotal == 0) {
        printf("No items were ordered. Thank you!\n");
        return 0;
    }

    // Calculate GST = 5%
    gst = subtotal * 0.05f;

    // Discount 10% if subtotal >= 500
    if (subtotal >= 500) {
        discount = subtotal * 0.10f;
    }

    total = subtotal + gst - discount;

    printf("Subtotal           : %.2f\n", subtotal);
    printf("GST @ 5%%           : %.2f\n", gst);

    if (discount > 0)
        printf("Discount @ 10%%     : -%.2f\n", discount);
    else
        printf("Discount           : 0.00\n");

    printf("---------------------------------------------\n");
    printf("Grand Total        : %.2f\n", total);
    printf("=============================================\n");
    printf("Thank you for ordering! Enjoy your meal :)\n");
    printf("=============================================\n");

    return 0;
}


