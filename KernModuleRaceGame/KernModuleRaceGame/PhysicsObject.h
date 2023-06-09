#pragma once
class PhysicsObject
{
	// formules
	// a = Fnetto / m 
	//  a = acceleration in m/s^2
	//  F = netoo force
	//  m = massa
	// 
	// 
	// 
	// Fw = u * N
	//  Fw = friction in N
	//  u = Friction Coeffient in 
	//  N = Normal Force in N
	// 
	// N = m * g 
	//  N = normal Force 
	//  m = massa 
	//  g = Gravitale kracht uitgedrukt in 9,81 m/s^s
	// 
	// Delta V = a *  Delta t
	//  a = acceleration in m/s^2
	//  V = volicity in m/s
	//  t = time in s
	// 
	// Delta t = 1 / 60, maar dan moet wel de framerate gelocked worden op 60 frames per seconden
	// 
	// 
	// Fnetto = F - Fw 
	//  F = Forwaardse kracht N
	//  Fw = friction in N 
	// 
	// S = V * t 
	// S= Displacement
	// V = Velocity
	// t = Time;
	// 

public: 
	//Grootheden
	float Velocity;
	float Acceleration;
	float NormalForce;
	float GravitationalForce = 9.81f;
	float Mass;
	float DeltaTime = 0.01666666666666666666666667;
	float DynamicFrictioncoefficient = 0.68f;
	float StaticFrictioncoefficient = 0.72f;
	float FrictionCoeffient;
	float Fmotor;
	float Fnetto;
	float Friction;
	float ForceNeededToMove;
	float Displacement;
	float currentForce = 0;
	float NewForce;


	// nevermind

	//functions
	//PhysicsObject();
	float CalculateVelocity(float _mass);
	float CalculateAcceleration(float _NettoForce, float _mass);
	float CalculateNettoForce(float _fMotor, float _friction);
	float CalculateFriction(float _frictionCoeffient, float _normalForce);
	float CalculateNormalForce(float _mass);
	float CalculateFrictionCoeffient(float _fMotor, float _normalForce);
	float CalculatingDisplacement(float _mass);
	float CalculateFmotor();
	void ShowInformation();


};

