#include "GameObject.h"
#include <algorithm>

GameObject::GameObject()
{
	Parent = nullptr;

	LocalPosition = MathClasses::Vector3(0, 0, 1);
	LocalRotation = 0;
	LocalScale = MathClasses::Vector3(1, 1, 1);
}

void GameObject::OnUpdate(float deltaTime)
{
}

void GameObject::OnDraw()
{
}


void GameObject::update(float deltaTime)
{
	OnUpdate(deltaTime);
}

void GameObject::Draw()
{
	OnDraw();
}

//////////////////////////

// Setting Childs And Parents

///////////////////////////

void GameObject::Setparent(GameObject* newParent)
{
	if (Parent != nullptr) {
		auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

		if (findIt != Parent->Children.end()) {
			Parent->Children.erase(findIt);
			Parent = nullptr;
		}
	}

	if (newParent != nullptr)
	{
		Parent = newParent;
		Parent->Children.push_back(this);
	}
}

GameObject* GameObject::GetParent()
{
	return Parent;
}

const GameObject* GameObject::GetParent() const
{
	return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
	return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
	return Children[childIndex];
}


/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

void GameObject::SetLocalPosition(MathClasses::Vector3 NewPosition)
{
	LocalPosition = NewPosition;
}

void GameObject::SetLocalPosition(float newx, float newy)
{
	LocalPosition = MathClasses::Vector3(newx, newy, LocalPosition.z);
}

void GameObject::SetlocalScale(MathClasses::Vector3 NewScale)
{
	LocalScale = NewScale;
}

void GameObject::SetLocalScale(float newX, float NewY)
{
	LocalScale = MathClasses::Vector3(newX, NewY, LocalScale.z);
}

float GameObject::SetLocalRotation(float newRotation)
{
	LocalRotation = newRotation;
	return LocalRotation;
}

////////////////////////////////

MathClasses::Vector3 GameObject::GetLocalPosition() const
{
	return LocalPosition;
}

MathClasses::Vector3 GameObject::GetlocalScale() const
{
	return LocalScale;
}
////////////////////////////////

MathClasses::Vector3 GameObject::GetWorldPosition() const
{
	MathClasses::Matrix3 worldMat = GetWorldMatrix();
	return MathClasses::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetWorldRotation() const
{
	MathClasses::Vector3 fwd = GetForwards();
	return atan2(fwd.y, fwd.x);
}

MathClasses::Vector3 GameObject::Getworldscale() const
{
	MathClasses::Matrix3 myTransform = GetWorldMatrix();

	return MathClasses::Vector3(MathClasses::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(),
			MathClasses::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(),
			1.0f);
}

MathClasses::Vector3 GameObject::GetForwards() const
{
	auto mat = GetWorldMatrix();
	return MathClasses::Vector3(mat[0], mat[1], mat[2]);
}

////////////////////////////////

MathClasses::Matrix3 GameObject::GetLocalMatrix() const
{
	return
		MathClasses::Matrix3::MakeTranslation(LocalPosition) *
		MathClasses::Matrix3::MakeRotateZ(LocalRotation) *
		MathClasses::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

MathClasses::Matrix3 GameObject::GetWorldMatrix() const
{
	if (Parent == nullptr) {
		return GetLocalMatrix();
	}
	else{
		return Parent->GetWorldMatrix() * GetLocalMatrix();
	}
}

/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

void GameObject::Translate(float x, float y)
{
	LocalPosition += MathClasses::Vector3(x, y, 0);
}

void GameObject::Translate(MathClasses::Vector3 translation)
{
	LocalPosition += translation;
}

void GameObject::Rotate(float radians)
{
	LocalRotation += radians;
}

void GameObject::Scale(float x, float y)
{
	LocalScale *= MathClasses::Vector3(x, y, 1);
}

void GameObject::Scale(MathClasses::Vector3 scalar)
{
	LocalScale *= scalar;
}


