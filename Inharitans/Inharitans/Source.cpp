#include<iostream>

using namespace std;

class Box {
private:
	double width;
	double height;
	double length;
public:
	double get_width() const {
		return width;
	}
	double get_height() const {
		return height;
	}
	double get_length() const {
		return length;
	}
	double set_width(double width) {
		if (width < 0) width = -width;
		return this->width = width;
	}
	double set_height(double height) {
		if (height < 0) height = -height;
		return this->height = height;
	}
	double set_length(double length) {
		if (length < 0) length = -length;
		return this->length = length;
	}
	//-----------Constructor
	Box(double width, double height, double length) : 
													width(set_width(width)), 
													height(set_height(height)), 
													length(set_length(length)) {
		cout << "BConstructor:\t" << endl;
	}
	~Box() {
		cout << "BDestructor:\t" << endl;
	}
	void print() {
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
		cout << "Length: " << length << endl;
	}
};

class GiftBox : public Box{

private:
	string cover;
	bool bant;
public:
	const string& get_cover() const {
		return this->cover;
	}
	bool get_bant() const {
		return this->bant;
	}
	GiftBox
	(
		double width, 
		double heigth, 
		double length, 
		const string& cover, 
		bool bant
	):Box(width, heigth, length)
	{
		this->cover = cover;
		this->bant = bant;
		cout << "BgConstructor:\t" << endl;
	}
	~GiftBox() {
		cout << "BgDestructor:\t" << endl;
	}
	void print() {
		Box::print();
		cout << cover << endl;
		cout << (bant ? "yes" : "no") << endl;
	}
};

ostream& operator<<(ostream& os, const Box& other){
	cout << "Width: " << other.get_width() << endl;
	cout << "Height: " << other.get_height() << endl;
	cout << "Length: " << other.get_length() << endl;

	return os;
}
ostream& operator<<(ostream& os, const GiftBox& other) {
	cout << "Width: " << other.get_width() << endl;
	cout << "Height: " << other.get_height() << endl;
	cout << "Length: " << other.get_length() << endl;

	cout << other.get_cover() << endl;
	cout << (other.get_bant() ? "yes" : "no") << endl;

	return os;
}

void main() {
	setlocale(LC_ALL, "");

	Box A(5, 3, 6);
	A.print();
	GiftBox B(2, 3, 7, "white", false);
	B.print();
	cout << B << endl;

}