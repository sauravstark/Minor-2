attribute vec3 aPos;
attribute vec4 aCol;
attribute vec3 aTex;

varying vec4 col;
varying vec3 tex;

void main()
{
	gl_Position = vec4(aPos.xy, -1.0, 1.0);
	col = aCol;
	tex = aTex;
}