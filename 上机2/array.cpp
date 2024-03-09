class Array
{
public:
	Array(int n);           // n个元素. 所有元素初始为 0
	Array(int*p, int n);      //用一个整型原生C数组初始化
	Array (const Array &other);     //拷贝构造函数
	~Array();                   //析构函数
	void print();                //输出所有元素
	void input();                //键盘输入所有元素
	void set(int index, int value);   //将index号元素的值设置为value
private:
        int * data;
        int size;  // number of elements

};


int main()
{
	Array arr1(4);
	arr1.input(); // 输入1 2 3 4 
	arr1.print(); // 输出1 2 3 4   
	arr1.set(5,6); // 输出数组越界！  
	arr1.print();  // 输出1 2 3 4 
	arr1.set(2,6);
	arr1.print();  // 输出1 2 6 4
	Array arr2 = arr1;  // 调用拷贝构造函数对arr2初始化 
	arr1.print();  // 输出1 2 6 4
	int arr[6] = {1,2,3,4,5,6};
	Array arr3(arr,6); 
	arr3.print();  // 输出1 2 3 4 5 6
	Array arr4(arr+2,4);
	arr4.print();  // 输出3,4,5,6 
	return 0; 
}