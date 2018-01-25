#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

// Single flame by feliposz (2017-10-12)

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;
uniform sampler2D backbuffer;

void main( void ) {

	vec2 position = 4.0 * ( gl_FragCoord.xy - 0.5*resolution.xy) / resolution.y;
	vec2 m = 2.0*(vec2(0.5, 0.5) - 0.5);
	//m.x = m.x * resolution.x / resolution.y;
	
	
	float a = 0.02 / length(position-m);
	float b = 0.01 / length(position-m);
	float c = 0.001 / length(position-m);
	
	float d = sin(10.0*10.0 + position.x*position.y);
	vec2 offset = -vec2(0.001*d, 0.009 + 0.001*d);
	vec4 prev = texture2D(backbuffer, offset + gl_FragCoord.xy/resolution.xy);
	
	gl_FragColor = 0.95 * prev + vec4(a, b, c,1.0);

}