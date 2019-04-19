//
// Created by Mark David on 19/04/2019.
//

#include "computercontroller.h"
ComputerController::ComputerController(AbstractScoring* scoring, bool look_ahead)
        :scoring(scoring), look_ahead(look_ahead)
{

}
void ComputerController::Update(Game* game)
{
    Score(game);
    int move_delta = game->current_shape.X()-best_move.X();
    int rotation_delta = game->current_shape.GetRot()-best_move.GetRot();

    if (rotation_delta<0) RotateShape(game, Shape::Rotation::CLOCKWISE);
    if (rotation_delta>0) RotateShape(game, Shape::Rotation::COUNTERCLOCKWISE);

    if (move_delta>0) MoveShape(game, Shape::Movement::LEFT);
    if (move_delta<0) MoveShape(game, Shape::Movement::RIGHT);

    if (move_delta==0 && rotation_delta==0) MoveShape(game, Shape::Movement::DOWN);

}
bool ComputerController::AlreadyScored(Shape shape)
{
    return shape.X()!=5 || shape.Y()!=0 || shape.GetRot()!=0;
}

void ComputerController::UpdateBestScore(Shape shape, float score)
{
    if (score>best_score) {
        best_score = score;
        best_move = shape;
    }
}

std::vector<Shape> ComputerController::GeneratePermutations(Shape shape)
{
    std::vector<Shape> permutations;
    for (int col = 0; col<10; col++) {
        for (int rot = 0; rot<4; rot++) {
            Shape permutation = shape;
            permutation.SetPos(col, 0);
            permutation.SetRot(rot);
            permutations.push_back(permutation);
        }
    }
    return permutations;
}

void ComputerController::Score(Game* game)
{
    if (!AlreadyScored(game->current_shape)) {
        best_score = -1e9f;
        for (auto& shape : GeneratePermutations(game->current_shape)) {
            Board board = PlaceInBoard(game->board, shape);
            if (look_ahead) {
                for (auto& shape_next : GeneratePermutations(game->next_shape)) {
                    Board board_next = PlaceInBoard(board, shape_next);
                    UpdateBestScore(shape, scoring->GetScore(board_next));
                }
            }
            else
                UpdateBestScore(shape, scoring->GetScore(board));
        }
    }
}
Board ComputerController::PlaceInBoard(Board board, Shape& shape)
{
    while (board.IsValidPosition(shape))
        shape.Move(Shape::Movement::DOWN);
    shape.Revert();
    board.Place(shape);
    return board;
}
ComputerController::~ComputerController()
{
    delete scoring;
}

