#pragma once
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
private:
	//グラフィックを入れる変数
	int m_handle;
	//グラフィックのサイズ
	int m_width;
	int m_height;
	//プレイヤーのポジション
	float m_posX;
	float m_posY;
};

