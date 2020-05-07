precision mediump float;

varying vec4 col;
varying vec3 tex;

uniform sampler2D texture00;
uniform sampler2D texture01;
uniform sampler2D texture02;
uniform sampler2D texture03;
uniform sampler2D texture04;
uniform sampler2D texture05;
uniform sampler2D texture06;
uniform sampler2D texture07;
uniform sampler2D texture08;
uniform sampler2D texture09;
uniform sampler2D texture10;
uniform sampler2D texture11;
uniform sampler2D texture12;
uniform sampler2D texture13;
uniform sampler2D texture14;
uniform sampler2D texture15;

void main()
{
	gl_FragColor = col;
	if (tex.z == 0.0) {
		gl_FragColor = texture2D(texture00, tex.xy) * col;
	}
	if (tex.z == 1.0) {
		gl_FragColor = texture2D(texture01, tex.xy) * col;
	}
	if (tex.z == 2.0) {
		gl_FragColor = texture2D(texture02, tex.xy) * col;
	}
	if (tex.z == 3.0) {
		gl_FragColor = texture2D(texture03, tex.xy) * col;
	}
	if (tex.z == 4.0) {
		gl_FragColor = texture2D(texture04, tex.xy) * col;
	}
	if (tex.z == 5.0) {
		gl_FragColor = texture2D(texture05, tex.xy) * col;
	}
	if (tex.z == 6.0) {
		gl_FragColor = texture2D(texture06, tex.xy) * col;
	}
	if (tex.z == 7.0) {
		gl_FragColor = texture2D(texture07, tex.xy) * col;
	}
	if (tex.z == 8.0) {
		gl_FragColor = texture2D(texture08, tex.xy) * col;
	}
	if (tex.z == 9.0) {
		gl_FragColor = texture2D(texture09, tex.xy) * col;
	}
	if (tex.z == 10.0) {
		gl_FragColor = texture2D(texture10, tex.xy) * col;
	}
	if (tex.z == 11.0) {
		gl_FragColor = texture2D(texture11, tex.xy) * col;
	}
	if (tex.z == 12.0) {
		gl_FragColor = texture2D(texture12, tex.xy) * col;
	}
	if (tex.z == 13.0) {
		gl_FragColor = texture2D(texture13, tex.xy) * col;
	}
	if (tex.z == 14.0) {
		gl_FragColor = texture2D(texture14, tex.xy) * col;
	}
	if (tex.z == 15.0) {
		gl_FragColor = texture2D(texture15, tex.xy) * col;
	}
}