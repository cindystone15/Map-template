#ifndef MAP_H
#define MAP_H

#include "Book.h"
#include "Employee.h"
#include <iostream>

template <typename KeyType, typename ValueType> class Map {
  private:
	struct MapPair {
		KeyType key;
		ValueType value;
	};

	MapPair* m_data;
	size_t m_size;

  public:
	Map() : m_data(nullptr), m_size(0) {}

	Map(const Map& src) : Map()
	{
		if (src.m_size > 0) {
			m_data = new MapPair[src.m_size];
			m_size = src.m_size;
			for (size_t i = 0; i < m_size; i++)
				m_data[i] = src.m_data[i];
		}
	}

	~Map()
	{
		delete[] m_data;
	}

	void Swap(Map& other)
	{
		{
			MapPair* tmp = m_data;
			m_data = other.m_data;
			other.m_data = tmp;
		}
		{
			size_t tmp = m_size;
			m_size = other.m_size;
			other.m_size = tmp;
		}
	}

	// This method returns true if you can add a key-value pair or false/
	// if you can't because it already exists.

	bool add(const KeyType& key, const ValueType& value)
    {
        if (find(key) == nullptr) {
            MapPair* new_data = new MapPair[m_size + 1];
            for (size_t i = 0; i < m_size; i++)
                new_data[i] = m_data[i];
            new_data[m_size] = MapPair{key, value};
            m_size++;
            delete[] m_data;
            m_data = new_data;
            return true;
        }
        else{
			std::cout<<"This key already exists"<<std::endl;
			 return false;
		}	
    }

	ValueType* find(const KeyType& key) const
	{
		for (size_t i = 0; i < m_size; ++i) {
			if (m_data[i].key == key) {
				return &m_data[i].value;
			}
		}
		return nullptr;
	}

	Map& operator=(Map src)
	{
		Swap(src);
		return *this;
	}

	template <typename _KeyType, typename _ValueType>
	friend std::ostream& operator<<(std::ostream& out,
									const Map<_KeyType, _ValueType>& src);
};

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& out, const Map<KeyType, ValueType>& src)
{
	out << "{";
	for (size_t i = 0; i < src.m_size; ++i) {
		out << "( ID:" << src.m_data[i].key << "->" << src.m_data[i].value
			<< ")";
		if (i < src.m_size - 1)
			out << ",\n";
	}
	out << "}";
	return out;
}


// chnage it to key and value rather than getname and getage

/*std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
	out << ", Name: " << employee.getName() <<  ", Position: " << employee.getPosition()<<", Age: " << employee.getAge();
	return out;
}
*/


#endif
