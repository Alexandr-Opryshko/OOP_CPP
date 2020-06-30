#include<iostream>
#include<string>

using std::cout;
using std::endl;

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
	// Constructors:

	Box(double width, double height, double length):
													width(set_width(width)),
													height(set_height(height)),
													length(set_length(length))
	{
		cout << "BConstructor:\t" << this << endl;
	}
	~Box() {
		cout << "BDestructor:\t" << this << endl;
	}
	void print() const {
		cout << width << endl;
		cout << height << endl;
		cout << length << endl;
	}
};

class GiftBox :public Box {
private:
	std::string cover;
	bool bant;
public:
	const std::string& get_cover() const {
		return this->cover;
	}
	bool get_bant()const {
		return this->bant;
	}
	GiftBox(
		double width, double height, double length,
		const std::string& cover, bool bant
	):Box(width, height, length) {
		this->cover = cover;
		this->bant = false;
		cout << "GiftBoxConstructor:\t" << this << endl;
	}
	~GiftBox() {

	}
	void print() const {
		Box::print();
		cout << cover << endl;
		cout << bant << (!bant ? "yes" : "no") << endl;
	}
};


std::ostream& operator<<(std::ostream& os, const Box& other) {
	cout << "Width:\t" << other.get_width() << endl;
	cout << "Height:\t" << other.get_height() << endl;
	cout << "Length:\t" << other.get_length() << endl;

	return os;
}
void main() {
	setlocale(LC_ALL, "");
	Box A(5, 6, -8);
	cout << A << endl;
	GiftBox gb(2, 1, 3, "with Flower",true);
	gb.print();
}