#pragma once
template <class K, class V>
class Map {

private:
	struct date {
		K key;
		V value;
		int index;
	} map[100];
	int count = 0;

public:
	void Set(K key, V value) {
		for (int i = 0; i < count; ++i) {
			if (map[i].key == key)
			{
				map[i].value = value;
			}
		}
	}
	

  bool Get(const K& key, V& value) {
	for (int i = 0; i < count; i++) {
		if (map[i].key == key) {
			value = map[i].value;
			return true;
		}
		return false;
	}
}

	int Count() {
		return count;
	}

	void Clear() {
		count = 0;
	}

	bool Delete(const K& key) {
		for (int i = 0; i < count; i++) {
			if (map[i].key == key) {
			for (int j = i; j < count; j++) {
					map[j] = map[j + 1];
				}
				count--;
				return 1;
			}
		}
		return 0;
	}

	bool Find(const V value) {
		for (int i = 1; i <= count; ++i) {
			if (map[i].value == value)
				return 1;
		}
		return 0;
	}

	bool Includes(const Map<K, V>& map) {
		for (int i = 0; i < count; i++) {
			if (!map.Find(map[i].value)) {
				return 0;
		}

			return 1;
		}

	}

	const date* begin() {
		return &map[1];
	}

	const date* end() {
		return &map[count + 1];
	}

	V& operator[](K key)
	{
		for (int i = 1; i <= count; ++i) {
			if (map[i].key == key) {
				return map[i].value;
			}
		}
		++count;
		map[count].key = key;
		map[count].index = count - 1;
	return map[count].value;
	}
};

