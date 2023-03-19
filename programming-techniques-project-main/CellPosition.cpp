#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}
//OD
bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	else
	{
		return false;
	}
	// this line sould be changed with your implementation
}
//OD
bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else
	{
		return false;
	}
	// this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}
//OD
bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if (hCell >= 0 && hCell < NumHorizontalCells && vCell >= 0 && vCell < NumVerticalCells)
	{
		return true;
	}
	else
	{
		return false;
	}
	// this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}
//OOZ //farida
int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition) // error 
{
	int h = cellPosition.HCell();
	int v = cellPosition.VCell();

	return (NumVerticalCells - 1 - v) * NumHorizontalCells + h + 1;
}

// Note:
// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

///TODO: Implement this function as described in the .h file

// farida
CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	int v = NumVerticalCells - 1 - ((cellNum - 1) / 11);
	int h = (cellNum - 1) % NumHorizontalCells;
	CellPosition position(v, h);
	return position;
	/// TODO: Implement this function as described in the .h file


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


}

// farida
void CellPosition::AddCellNum(int addedNum)
{
	int Cellnum = 0;
	Cellnum = GetCellNum();
	Cellnum = Cellnum + addedNum;
	if (Cellnum > NumHorizontalCells * NumVerticalCells)
	{
		Cellnum = NumHorizontalCells * NumVerticalCells;
	}
	CellPosition cellPosition1 = GetCellPositionFromNum(Cellnum);
	SetVCell(cellPosition1.VCell());
	SetHCell(cellPosition1.HCell());

	/// TODO: Implement this function as described in the .h file
	// Note: this function updates the data members (vCell and hCell) of the calling object

}

bool CellPosition::SameCell(CellPosition y)
{
	if ((this->HCell() == y.HCell()) && (this->VCell() == y.VCell())) {return true;}
	
	else {return false;}

}