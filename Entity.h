#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	void Init(int posx, int posy, int w, int h, int s);
	void GetRect(int *posx, int *posy, int *w, int *h);
	int  GetX();
	int GetY();
	void SetY(int y);
	void ShutDown();
	bool IsAlive();
	void Move(int dx, int dy);
	void MoveDown();
private:
	int x, y;
	int width, height;
	int speed;
	bool is_alive;
};

