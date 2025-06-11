// vect3.cpp -- использование функций STL
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

const std::string BASE_STR = "Rating\tPrice\tTitle";

struct Review {
  std::string title;
  int rating;
  double price;
};

bool operator<(const std::shared_ptr<Review>& r1,
  const std::shared_ptr<Review>& r2);
bool worseThan(const std::shared_ptr<Review>& r1,
  const std::shared_ptr<Review>& r2);
bool sortPrice(const std::shared_ptr<Review>& r1,
  const std::shared_ptr<Review>& r2);
bool fillReview(Review& rr);
void showReview(const std::shared_ptr<Review>& rr);
void showMenu();

int main()
{
  std::vector<std::shared_ptr<Review>> books;
  Review temp;
  while (fillReview(temp)) {
    std::shared_ptr<Review> ptr (new Review);
    ptr->title = temp.title;
    ptr->rating = temp.rating;
    ptr->price = temp.price;
    books.push_back(ptr);
  }
  if (books.size() > 0) {
    int choice;
    showMenu();
    while (std::cin >> choice && choice != 6) {
      switch (choice) {
        case 1: std::cout << BASE_STR << std::endl;
                std::for_each(begin(books), end(books), showReview);
                std::cout << "Your choice: ";
                break;
        case 2: std::cout << BASE_STR << std::endl;
                std::sort(begin(books), end(books));
                std::for_each(begin(books), end(books), showReview);
                std::cout << "Your choice: ";
                break;
        case 3: std::cout << BASE_STR << std::endl;
                std::sort(begin(books), end(books), worseThan);
                std::for_each(begin(books), end(books), showReview);
                std::cout << "Your choice: ";
                break;
        case 4: std::cout << BASE_STR << std::endl;
                std::sort(begin(books), end(books), sortPrice);
                std::for_each(begin(books), end(books), showReview);
                std::cout << "Your choice: ";
                break;
        case 5: std::cout << BASE_STR << std::endl;
                std::sort(begin(books), end(books), sortPrice);
                std::for_each(rbegin(books), rend(books), showReview);
                std::cout << "Your choice: ";
                break;
        default: std::cout << "Wrong input! Try again!\n";
                 showMenu();
                 break;
      }
    }
  } else
    std::cout << "No entries. ";
  std::cout << "Bye!\n";

  return 0;
}

// Перегруженный operator<() используется для сортировки по названию
bool operator<(const std::shared_ptr<Review>& r1,
  const std::shared_ptr<Review>& r2)
{
  if (r1->title < r2->title)
    return true;
  else if (r1->title == r2->title && r1->rating < r2->rating)
    return true;
  else if (r1->title == r2->title && r1->rating == r2->rating &&
    r1->price < r2->price)
    return true;
  else
    return false;
}

// Сортировка по рейтингу
bool worseThan(const std::shared_ptr<Review>& r1, 
  const std::shared_ptr<Review>& r2)
{
  if (r1->rating < r2->rating)
    return true;
  else
    return false;
}

// Сортировка по цене
bool sortPrice(const std::shared_ptr<Review>& r1,
  const std::shared_ptr<Review>& r2)
{
  if (r1->price < r2->price)
    return true;
  else
    return false;
}

// Ввод значений
bool fillReview(Review& rr)
{
  std::cout << "Enter book title <quit to quit>: ";
  std::getline(std::cin, rr.title);
  if (rr.title == "quit")
    return false;
  std::cout << "Enter book rating: ";
  std::cin >> rr.rating;
  if (!std::cin)
    return false;
  std::cout << "Enter book price: ";
  std::cin >> rr.price;
  if (!std::cin)
    return false;
  
  // Удаление остатков строки ввода
  while (std::cin.get() != '\n')
    continue;
  
  return true;
}

// Вывод всех значений
void showReview(const std::shared_ptr<Review>& rr)
{
  std::cout << rr->rating << "\t" << rr->price << "\t"
            << rr->title << std::endl;
}

// Показ меню
void showMenu()
{
  std::cout << "Please, select an action:\n";
  std::cout << "1. Display in the original order;\n";
  std::cout << "2. Display in the alphabet order;\n";
  std::cout << "3. Display by rating;\n";
  std::cout << "4. Display by price (increasing);\n";
  std::cout << "5. Display by price (decreasing);\n";
  std::cout << "6. Quit;\n";
  std::cout << "Your choice: ";
}