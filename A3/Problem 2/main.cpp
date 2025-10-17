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
    void intersection(const Rectangle &otherRect) const
    {
        int farthestRight = max(left, otherRect.left);     // Left
        int lowestTop = max(top, otherRect.top);           // Top
        int closestLeft = min(right, otherRect.right);     // Right
        int highestBottom = min(bottom, otherRect.bottom); // Bottom

        // Check if rectangles overlap
        if (farthestRight < closestLeft && lowestTop < highestBottom)
        {
            Rectangle rectI(farthestRight, lowestTop, closestLeft - farthestRight, highestBottom - lowestTop); // intersection rectangle
            rectI.displayRect();
        }
        else
        {
            cout << "No Intersection\n";
        }
    }
    void displayRect()
    {
        cout << "Rectangle from (" << left << ", " << top << ") to ("
             << right << ", " << bottom << ")" << endl;
    }
    void checkPoint(int x, int y)
    {
        if (x >= left && x <= right && y >= top && y <= bottom)
        {
            cout << "\n\033[32mIs Inside Rectangle\033[0m";
            // return true;
        }
        else
        {
            cout << "\n\033[31mIs Outside Rectangle\033[0m";
            // return false;
        }
    }
};

int main()
{
    Rectangle r1(0, 0, 5, 5);
    r1.displayRect();
    Rectangle r2(4, 4, 7, 2);
    r2.displayRect();
    cout << "\n\033[33mIntersection of r1 and r2:\033[0m\n";
    r1.intersection(r2);

    r1.checkPoint(3, 4);
    r2.checkPoint(2, 3);
    return 0;
}