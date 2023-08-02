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

	//“–‚½‚è”»’è‚ğ‚Æ‚é‚½‚ß‚É•K—v‚È•Ï”
	float GetLeft() const;
	float GetRight() const;
};
