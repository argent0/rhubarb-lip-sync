#pragma once

#include "EnumConverter.h"

// The classic Hanna-Barbera mouth shapes A-F phus the common supplements G-H
// For reference, see http://sunewatts.dk/lipsync/lipsync/article_02.php
// For visual examples, see https://flic.kr/s/aHsj86KR4J. Their shapes "BMP".."L" map to A..H.
enum class Shape {
	// Basic shapes
	
	A,	// Closed mouth (M, B, P)
	B,	// Clenched teeth (most consonants, some vowels like EE as in b[ee])
	C,	// Open mouth (vowels like m[e]n, s[u]n, s[a]y)
	D,	// Mouth wide open (vowels like f[a]ther, b[a]t, wh[y])
	E,	// Rounded mouth (vowels like [o]ff)
	F,	// Puckered lips (y[ou], b[o]y, [w]ay)

	// Extended shapes

	G,	// "F", "V"
	H,	// "L"
	X,	// Idle

	EndSentinel
};

class ShapeConverter : public EnumConverter<Shape> {
public:
	static ShapeConverter& get();
protected:
	std::string getTypeName() override;
	member_data getMemberData() override;
};

std::ostream& operator<<(std::ostream& stream, Shape value);

std::istream& operator>>(std::istream& stream, Shape& value);

inline bool isClosed(Shape shape) {
	return shape == Shape::A || shape == Shape::X;
}