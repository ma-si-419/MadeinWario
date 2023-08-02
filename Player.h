#pragma once
class Player
{
public:
	Player();
	~Player();

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
	//プレイヤーの移動速度
	float m_speedX;
	float m_speedY;
	//スペースが押されたか判断する変数
	bool m_spaceFlag;

};

