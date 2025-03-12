PINLINE v2 V2(i32 x, i32 y) 
{
	return (v2){x, y};
}

PINLINE v2 V2_Add(v2 a, v2 b) 
{
	return (v2){a.x + b.x, a.y + b.y};
}

PINLINE v2 V2_Subtract(v2 a, v2 b) 
{
	return (v2){a.x - b.x, a.y - b.y};
}

PINLINE v2 V2_Scale(v2 v, i32 scalar) 
{
	return (v2){v.x * scalar, v.y * scalar};
}

PINLINE v2 V2_Negate(v2 v) 
{
	return (v2){-v.x, -v.y};
}

