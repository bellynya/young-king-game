//---------------------------------------------------------------------------

#ifndef class_LoadToGridH
#define class_LoadToGridH
#include <Vcl.Grids.hpp>
#include "class_characters.h"
//---------------------------------------------------------------------------
class ResultLogin
{
	public:
	TStringGrid *sgResults;
	int current_position_cols = 0, current_position_rows = 1;

	void LoadDataToGrid(King *king)
	{
		sgResults->Cells[current_position_cols][current_position_rows] = king->name;
		sgResults->Cells[current_position_cols+1][current_position_rows] = king->year_count;
	    current_position_rows++;
	}
};
#endif
