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

    int PrevX() const;

    int PrevY() const;

    int PrevRot() const;

    void X(int x);

    void Y(int y);

    void SetPos(int x, int y);

    void SetRot(int rot);

    int GetRot() const;

    int Size() const;

    void Move(Movement mov);

    void Rotate(Rotation rot);

    void Revert();

    Shape();

    Shape(int size, const char *shape);

    Shape(const Shape &other);

    Shape &operator=(const Shape &other);

    bool operator==(const Shape& rhs);

private:
    int xPos{}, yPos{};
    int rotation{};

    int oldxPos = 0, oldyPos = 0;
    int oldrotation{};
    int size{};
    const char *shape{};

    void UpdateOld();
};


#endif //TETRISVS_SHAPE_H
