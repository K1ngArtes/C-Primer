#include <iostream>
#include <Sales_item.h>

/*
 * This program provides report that shows, for each book, the total number of copies sold,
 * the total revenue, and the average sale price
 */
int main() {
    Sales_item total;
    if(std::cin >> total) {
        Sales_item nextBook;
        while(std::cin >> nextBook) {
            if(total.isbn() == nextBook.isbn()) {
                total += nextBook;
            } else {
                std::cout << total << std::endl;
                total = nextBook;
            }
        }
        std::cout << total << std::endl;

    }
}
