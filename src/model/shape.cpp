//
// Created by Mark David on 26/03/2019.
//

#include "shape.h"

Shape::Shape(int size, const char *shape) : size(size), shape(shape), xPos(5), yPos(0), rotation(0),
                                            oldxPos(xPos), oldyPos(yPos), oldrotation(rotation) {}

Shape::Shape() : size(-1), shape(nullptr), xPos(-1), yPos(-1), rotation(-1),
                 oldxPos(-1), oldyPos(-1), oldrotation(-1) {}

Shape::Shape(const Shape &other) = default;

Shape &Shape::operator=(const Shape &other) = default;

char Shape::GetSymbolAt(int x, int y) const {
    switch (rotation) {
        case 0:
        default:
            return shape[x + y * size];
        case 1:
            return shape[((x + 1) * size) - (y + 1)];
        case 2:
            return shape[((size * size) - 1) - x - y * size];
        case 3:
            return shape[(size * (size - 1)) - (x * size) + y];
    }


}

int Shape::Size() const {
    return size;
}

int Shape::X() const {
    return xPos;
}

int Shape::Y() const {
    return yPos;
}

void Shape::X(int x) {
    xPos = x;
}

void Shape::Y(int y) {
    yPos = y;
}

void Shape::SetPos(int x, int y) {
    X(x);
    Y(y);
}


void Shape::Move(Shape::Movement mov) {
    UpdateOld();
    if (mov == Shape::Movement::DOWN)
        yPos++;
    else
        xPos += (int) mov;
}

void Shape::Rotate(Shape::Rotation rot) {
    UpdateOld();
    rotation = (rotation + (int) rot);
    rotation = (rotation < 0) ? rotation + 4 : rotation;
    rotation = (rotation >= 4) ? rotation - 4 : rotation;
}

void Shape::Revert() {
    rotation = oldrotation;
    xPos = oldxPos;
    yPos = oldyPos;
}

void Shape::UpdateOld() {
    oldyPos = yPos;
    oldxPos = xPos;
    oldrotation = rotation;
}

void Shape::SetRot(int rot) {
    rotation = rot;
}

int Shape::GetRot() const {
    return rotation;
}

