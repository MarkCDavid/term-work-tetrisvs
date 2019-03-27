//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_SHAPE_H
#define TETRISVS_SHAPE_H


class Shape {
public:
    enum class Rotation {
        CLOCKWISE = 1, COUNTERCLOCKWISE = -1
    };
    enum class Movement {
        LEFT = -1, DOWN = 0, RIGHT = 1
    };

    char GetSymbolAt(int x, int y) const;

    int X() const;

    int Y() const;

    void X(int x);

    void Y(int y);

    void SetPos(int x, int y);

    int Size() const;

    void Move(Movement mov);

    void Rotate(Rotation rot);

    void Revert();

    Shape();

    Shape(int size, char *shape);

    Shape(const Shape &other);

    Shape &operator=(const Shape &other);

private:
    int xPos, yPos;
    int rotation;

    int oldxPos, oldyPos;
    int oldrotation;
    int size;
    const char *shape;

    void UpdateOld();
};


#endif //TETRISVS_SHAPE_H
