#include "Drive.h"


Drive::Drive()
{
    // InitPIDValues();
    // DrivePID("Drive", DrivePIDValues);

    frontLeft.SetInverted(true);
    frontRight.SetInverted(true);
    backLeft.SetInverted(true);
    backRight.SetInverted(true);
}

void Drive::RunPIDControl(double inputAngle)
{
    MyMecanumDrive.DriveCartesian(0, 0, DrivePID.Calculate(inputAngle));
}

void Drive::RunDrive(double xboxLY, double xboxLX, double xboxRX)
{
    MyMecanumDrive.DriveCartesian(xboxLY, xboxLX, xboxRX);
}

void Drive::InitPIDValues()
{
    DrivePIDValues.kP = 6e-5, DrivePIDValues.kI = 1e-6, DrivePIDValues.kD = 0, DrivePIDValues.kMaxOutput = 1.0, DrivePIDValues.kMinOutput = -1.0;
    DrivePIDValues.setpoint = 0;
    DrivePIDValues.positionTolerance = 1, DrivePIDValues.velocityTolerance = 1;
}

bool Drive::InRange()
{
    return DrivePID.AtSetpoint();
}