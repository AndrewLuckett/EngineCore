#version 400 core

out vec4 colour;

in vec2 texCo;

uniform sampler2D texSampler;

void main() {
    colour = texture(texSampler, texCo);
};
