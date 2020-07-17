

struct SDamage_types {
	float slice,pierce,blunt;
};

class CWeaponItem : public CBaseItem {
public:
	CWeaponItem() {}
	
	SDamage_types get_damage() { return damage; }
	float get_uses_left() { return uses_left; }
	bool is_broken() { return broken; }
	CSkill* get_skill(int skill_id) { return using_skills[skill_id]; }
	int get_max_range() { return max_range; }
	int get_min_range() { return min_range; }
	
protected:
	SDamage_types damage;
	float uses_left; // 0 means broken
	bool broken;
	vector<CSkill*> using_skills;
	int max_range, min_range;
};