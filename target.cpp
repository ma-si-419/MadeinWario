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

	//�����蔻����Ƃ邽�߂ɕK�v�ȕϐ�
	float GetLeft() const;
	float GetRight() const;
};
