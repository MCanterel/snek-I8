#pragma once

#include "Board.h"
#include <vector>

class Snake
{
private:	
	class Segment
	{
	public:
		Segment(const Location& _loc);
		Segment(Color c_in);
		//void InitHead( const Location& loc );
		//void InitBody( Color c );
		void Follow( const Segment& next );
		void MoveBy( const Location& delta_loc );
		void Draw( Board& brd ) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake( const Location& loc );
	void MoveBy( const Location& delta_loc );
	Location GetNextHeadLocation( const Location& delta_loc ) const;
	void GrowAndMoveBy( const Location& delta_loc );
	void Draw( Board& brd ) const;
	bool IsInTileExceptEnd( const Location& target ) const;
	bool IsInTile( const Location& target ) const;
	size_t GetLength() const;

private:
	static constexpr int nBodyColors = 4;
	static constexpr Color bodyColors[nBodyColors] = {
		{ 10,100,32 },
		{ 10,130,48 },
		{ 18,160,48 },
		{ 10,130,48 }
	};
	static constexpr Color headColor = Colors::Yellow;
	static constexpr int nSegmentsMax = 100;
	std::vector <Segment> segments; // [nSegmentsMax];
	//int nSegments = 1;
};