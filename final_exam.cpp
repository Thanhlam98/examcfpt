#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <string.h>

class Point {
public:
    Point() : m_x(0), m_y(0) {}
    Point(int x, int y) : m_x(x), m_y(y) {}
    Point(const Point &point) : m_x(point.m_x), m_y(point.m_y) {}

    int getX() const {return m_x;}
    void setX(int x) {m_x = x;}
    int getY() const {return m_y;}
    void setY(int y) {m_y = y;}
    Point operator+(const Point& point) const {
        return Point(m_x + point.m_x, m_y + point.m_y);
    }
    void operator+=(const Point& point) {
        m_x += point.m_x;
        m_y += point.m_y;
    }
    Point operator-(const Point& point) const {
        return Point(m_x - point.m_x, m_y - point.m_y);
    }
    void operator-=(const Point& point) {
        m_x -= point.m_x;
        m_y -= point.m_y;
    }
    Point& operator=(const Point& point) {
        m_x = point.m_x;
        m_y = point.m_y;
        return *this;
    }
    bool operator==(const Point& point) const {
        return ((m_x == point.m_x) && (m_y == point.m_y));
    }
    bool operator!=(const Point& point) const {
        return ((m_x != point.m_x) || (m_y != point.m_y));
    }
    Point operator*(float f) const {
        return Point((int)(m_x * f), (int)(m_y * f));
    }
protected:
    int m_x;
    int m_y;
};

class Item {
public:
    Item(Item* parentItem = nullptr) : m_parentItem(parentItem) {
        if (m_parentItem) {
            m_parentItem->m_childItems.push_back(this);
        }
    }
    ~Item() {
        if (m_parentItem) {
            for (auto iter = m_parentItem->m_childItems.begin(); iter != m_parentItem->m_childItems.end();) {
                if (*iter == this) {
                    iter = m_parentItem->m_childItems.erase(iter);
                } else {
                    ++iter;
                }
            }
        }
    }
    Item* getParentItem() const {
        return m_parentItem;
    }
    std::vector<Item*> getChildItems() const {
        return m_childItems;
    }
    int getX() const {return m_x;}
    void setX(int x) {m_x = x;}
    int getY() const {return m_y;}
    void setY(int y) {m_y = y;}
    int getWidth() const {return m_width;}
    void setWidth(int width) {m_width = width;}
    Point getPosition() const {
        return Point(m_x, m_y);
    }
    void setPosition(const Point& point) {
        m_x = point.getX();
        m_y = point.getY();
    }
protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
private:
    Item* m_parentItem;
    std::vector<Item*> m_childItems;
};

class TextItem : public Item {
public:
    TextItem(Item* parentItem = nullptr) : Item(parentItem), m_text(nullptr) {}
    TextItem(const TextItem& textItem) : Item(textItem.getParentItem()), m_text(nullptr) {
        *this = textItem;
    }
    ~TextItem() {
        if (m_text) {
            delete []m_text;
            m_text = nullptr;
        }
    }
    TextItem& operator=(const TextItem& textItem) {
        Item::operator=(textItem);
        setText(textItem.m_text);
        return *this;
    }
    const char * getText() const {return m_text;}
    void setText(const char * text) {
        if (m_text) {
            delete []m_text;
            m_text = nullptr;
        }
        
        if (text) {
            auto len = strlen(text);
            m_text = new char[len + 1];
            memcpy(m_text, text, len + 1);
        }
    }
protected:
    char * m_text;
};

void readTextItems(std::vector<TextItem*>& items) {
    for (;;) {
        std::cout << "Do you want to add a TextItem?: ";
        std::string answer;
        std::cin >> answer;
        std::cin.ignore();
        if (answer == "y" || answer == "Y") {
            int x;
            int y;
            std::string text;

            std::cout << "Please enter x: ";
            std::cin >> x;
            std::cin.ignore();
            std::cout << "Please enter y: ";
            std::cin >> y;
            std::cin.ignore();
            std::cout << "Please enter text: ";
            std::getline(std::cin, text);
            auto textItem = new TextItem();
            textItem->setX(x);
            textItem->setY(y);
            textItem->setText(text.data());
            items.push_back(textItem);
        } else if (answer == "n" || answer == "N") {
            break;
        }
    }
}

void saveTextItems(const std::vector<TextItem*>& items, const char * filename) {
    std::thread th([&]() {
        std::ofstream file(filename);
        for (auto textItem : items) {
            file << textItem->getX() << ' ' << textItem->getY() << ' ' << textItem->getText() << std::endl;
        }
    });
    th.join();
}

int main() {
    std::vector<TextItem*> items;
    readTextItems(items);
    saveTextItems(items, "items.txt");
    return 0;
}