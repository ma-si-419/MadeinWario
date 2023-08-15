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
private:

	//グラフィックを入れる変数
	int m_handle;
	int m_clearHandle;
	int m_failedHandle;
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
	//成功したか判断する変数
	bool m_clearFlag;
	bool m_failedFlag;
};

