#include <iostream>
#include <vector>

using namespace std;

class Rectangle
{
private:
    int left, top, width, height, right, bottom;
    // int topLeft, topRight, bottomLeft, bottomRight;

public:
    Rectangle(int left_, int top_, int width_, int height_)
    {
        left = left_; // x1
        top = top_;   // y1
        width = width_;
        height = height_;
        right = left + width_;  // x2
        bottom = top + height_; // y2
    }
    Rectangle intersection(const Rectangle &other) const
    {
        int farthestRight = std::max(left, other.left);//Left
        int lowestTop = std::max(top, other.top);//Top
        int closestLeft = std::min(right, other.right);//Right
        int highestBottom = std::min(bottom, other.bottom);//Bottom

        // Check if rectangles actually overlap
        if (farthestRight < closestLeft && lowestTop < highestBottom)
            return Rectangle(farthestRight, lowestTop, closestLeft-farthestRight, highestBottom-lowestTop); // intersection rectangle
        else
            return Rectangle(0, 0, 0, 0); // no intersection
    }
    void print() const
    {
        cout << "Rectangle from (" << left << ", " << top << ") to ("
             << right << ", " << bottom << ")" << endl;
    }
    bool checkPoint(int x, int y)
    {
        if (x >= left && x <= right && y >= top && y <= bottom)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Rectangle r1(0, 0, 5, 5);
    Rectangle r2(4, 4, 7, 2);
    cout << "\nIntersection of r1 and r2:\n";
    Rectangle inter12 = r1.intersection(r2);
    inter12.print();

    cout << (r1.checkPoint(3, 4) ? "\nIs Inside Rectangle" : "\nIs Outside Rectangle");
    cout << (r2.checkPoint(2, 3) ? "\nIs Inside Rectangle" : "\nIs Outside Rectangle");
    return 0;
}