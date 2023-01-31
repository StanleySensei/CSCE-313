#include <iostream>
#include <stdio.h>
#include <string.h>

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};


class Shape {
    public: //shape cant be access in main without defining as public
    int vertices;
    Point** points;

    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices+1];

        for(unsigned int i = 0; i <= vertices; i++){
            points[i] = new Point(); //allocating empty elements
        }
    }

    ~Shape () {//destructor to delete allocated memory
        for(unsigned int i = 0; i <= vertices; i++){
            delete points[i]; //deleting each element in the points array
        }
        vertices = 0;
        
        delete[] points; //deleting points array
        
    }

    void addPoints (Point* pts) {
        
        // std::cout << "PTS: " << pts << " for verts:  " << vertices << std::endl;
        // std::cout << "SZ PTS: " << sizeof(pts) << std::endl;
        // for (int i = 0; i <= vertices; i++) {
        //     std::cout<< pts[i%vertices]->x << " at " << i << " for verts:  " << vertices << std::endl;
        //     memcpy(&points[i], &pts[i%vertices], sizeof(Point));
        //     // std::cout << pts ->x << std::endl;
        //     //pts++;
        // }
        for (int i = 0; i <= vertices; i++) {
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
        //std::cout << "FIN ADDPTS" << std::endl;

        
    }

    double area () {
        int temp = 0;
        for (int i = 0; i < vertices; i++) {//fixed issue with # of vertices being read
            // FIXME: there are two methods to access members of pointers
            //        use one to fix lhs and the other to fix rhs

            Point rhs_mult_right = *points[i];
            Point rhs_mult_left = *points[i+1];
            // std::cout << "PTS IS " << points << std::endl;
            int lhs = points[i]->x * points[i+1]->y;
            // int rhs = points[i+1] -> x * points[i] -> y;
            int rhs = rhs_mult_left.x * rhs_mult_right.y;
            temp += (lhs - rhs);
        }
        double area = abs(temp)/2.0;
        return area;
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)

    //Hello
    struct Point tri1 = Point(0,0);
    Point* tri2 =  new Point(1,2);
    struct Point tri3;
    tri3.x = 2;
    tri3.y = 0;
    // Point tri3;
    // tri3.x = 2;
    // tri3.y = 0;

    

    // adding points to tri
    // Point triPts[3] = {tri1, tri2, tri3};
    // Shape* tri = new Shape(3);
    // tri -> addPoints(&triPts);
    Point triPts[3] = {tri1, *tri2, tri3};
    Shape* tri = new Shape(3);
    tri -> addPoints(triPts);

    // FIXME: create the following points using your preferred struct
        //    definition:
        //      quad1 = (0, 0)
        //      quad2 = (0, 2)
        //      quad3 = (2, 2)
        //      quad4 = (2, 0)

    struct Point quad1 = Point{0,0};
    struct Point quad2 = Point{0,2};
    struct Point quad3 = Point{2,2};
    struct Point quad4 = Point{2,0};


    // // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad -> addPoints(quadPts);

    // FIXME: print out area of tri and area of quad
    std::cout << "Area of tri: " << (tri -> area()) << std::endl;
    std::cout << "Area of quad: " << (quad -> area()) << std::endl;
    delete tri2;
    delete tri;
    delete quad;

}
