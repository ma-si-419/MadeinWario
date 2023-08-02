#include "target.h"
class Target
{
public:
	Target();
	~Target();

	void Init();
	void Update();
	void Draw() const;

	void SetGraphHandle(int handle);

	//当たり判定をとるために必要な変数
	float GetLeft() const;
	float GetRight() const;
};
