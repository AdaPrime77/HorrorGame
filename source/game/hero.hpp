bool InitializeHero(void);
int HeroMove(bool push_key[256], int map_data[640][480]);
int SendHeroDataX(void);
int SendHeroDataY(void);
short SendHeroDataD(void);
bool SendHeroDataS(void);
int HeroSerch(int one_key[256], int map[640][480], int direction);