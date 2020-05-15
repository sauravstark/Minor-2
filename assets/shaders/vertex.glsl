attribute vec4 aPos;
attribute vec4 aCol;
attribute vec3 aTex;

varying vec4 col;
varying vec3 tex;

void main()
{
	mat4 projection;
	projection[0] = vec4((2.0/1600.0), 0.0, 0.0, 0.0);
	projection[1] = vec4(0.0, (2.0/900.0), 0.0, 0.0);
	projection[2] = vec4(0.0, 0.0, 1.0, 0.0);
	projection[3] = vec4(0.0, 0.0, 0.0, 1.0);

	gl_Position = projection * aPos;
	col = aCol;
	tex = aTex;
}