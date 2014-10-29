interface Hashmap<t>
{
	command void insert(uint32_t key, t input);
	command void remove(uint32_t key);
	command void clear();
	command t get(uint32_t key);
	command uint32_t getIndex(uint32_t key);
	command bool contains(uint32_t key);
	command bool isEmpty();
	command uint16_t size();
	command uint32_t * getKeys();
}
