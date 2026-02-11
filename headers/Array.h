#ifndef ARRAY_H
#define ARRAY_H



class Array {
private:
    int *items;
    int size;
    int length;
public:
    Array(const int arrSize);

    void Fill();

    void Display() const;

    int getLength() const;

    int getSize() const;

    int Search(int key);

    void Append(int newItem);

    void Insert(int index, int newItem);

    void Delete(int index);

    void Enlrage(int newSize);

    void Merge(Array other);
};




#endif //ARRAY_H
