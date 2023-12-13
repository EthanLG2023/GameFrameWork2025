#pragma once
class Actor;

class Component
{
public:

	Component();
	Component(Actor* owner, const char* name);

	virtual  ~Component();

	/// <summary>
	/// Called before the first update
	/// </summary>
	virtual void start() {};

	/// <summary>
	/// Called every time the game loops
	/// </summary>
	/// <param name="deltaTime">The amount of time that has passed between this frame and the next</param>
	virtual void update(float deltaTime) {};

	/// <summary>
	/// Called after update in order to update the visuals
	/// </summary>
	virtual void draw() {};

	/// <summary>
	/// Is called when the scene ends or an actor is removed
	/// </summary>
	virtual void end() {};

	virtual void onCollision(Actor* other) {};

	/// <summary>
	/// called right before the actor is going to be destroyed.
	/// </summary>
	virtual void onDestroy() {};

	/// <summary>
	/// gets the name of this component
	/// </summary>
	/// <returns>it usually the type name</returns>
	const char* getName() { return m_name; }

	/// <summary>
	/// gets the actor this component is attached too
	/// </summary>
	/// <returns></returns>
	Actor* getOwner() { return m_owner; } 

private:
	const char* m_name;
	Actor* m_owner;
};

