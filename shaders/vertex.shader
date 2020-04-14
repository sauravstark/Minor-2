attribute vec2 aPosition;
attribute vec4 aColor;

varying vec4 ourColor;

void main()
{
	gl_Position = vec4(aPosition.xy, -1.0, 1.0);
	ourColor = aColor;
}