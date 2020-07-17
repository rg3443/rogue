
class CFoodItem : public CBaseItem {
public:
	CFoodItem() {}
	void set_calories(float calories) { this->calories = calories; }
	float get_calories() { return calories; }
	
protected:
	float calories; // ammount of
	bool poisoned;
	
};