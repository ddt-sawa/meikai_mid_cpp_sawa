/*演習7-3 左上直角の二等辺三角形RectEquilTriangleLUと、右下直角の二等辺三角形RectEquilTriangleRBを作成せよ。*/

#ifndef ___TwoDimension
#define ___TwoDimension

//面積を求めるための二次元クラス(抽象クラス)
class TwoDimensionClass {
public:

	//純粋仮想デストラクタ
	virtual ~TwoDimensionClass() = 0;

	//面積を求める純粋仮想関数
	virtual double getArea() const = 0;
};

//仮想デストラクタ
inline TwoDimensionClass::~TwoDimensionClass() {}

#endif
