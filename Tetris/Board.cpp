#include "Board.h"
#include "raylib.h"
#include <assert.h>

Board::Cell::Cell()
	:
	bExists(false),
	c(WHITE)
{

}

void Board::Cell::SetColor(Color c_in)
{
	c = c_in;
	bExists = true;
}

void Board::Cell::Remove()
{
	bExists = false;
}

Color Board::Cell::GetColor() const
{
	return c;
}

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize_in, int padding)
	:
	screenPos(screenPos),
	width(widthHeight.GetX()),
	height(widthHeight.GetY()),
	cellSize(cellSize_in),
	padding(padding)
{
	assert(width > 0 && height > 0); // if assertion fails : width / height is smaller than one
	assert(cellSize > 0); // if assertion fails : the cell size is smaller than 1
	cells.resize(width*height);
}

void Board::SetCell(Vec2<int> pos, Color c)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height); // if assertion triggers : x/y is out of bounds.
	cells[width * pos.GetY() + pos.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> pos) const
{
	assert(pos.GetX() >= 0, pos.GetX() < width && pos.GetY() >= 0, pos.GetY() < height);
	Color c = cells[pos.GetY() * width + pos.GetX()].GetColor();
	Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
	raycpp::DrawRectangle(topLeft, Vec2<int>{ cellSize, cellSize } - padding, c);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; ++iY)
	{
		for (int iX = 0; iX < width; ++iX)
		{
			DrawCell({ iX, iY });
		}
	}
}