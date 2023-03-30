#include "pch.h"
#include "CFill.h";
#include <stack>
#include <utility>

void CFill::BoundaryFill(CDC* pDC, int x, int y, COLORREF boundaryColor, COLORREF fillColor) {
	if (pDC->GetPixel(x, y) == boundaryColor) return;
	pDC->SetPixel(x, y, fillColor);
	if (pDC->GetPixel(x + 1, y) != fillColor) BoundaryFill(pDC, x + 1, y, boundaryColor, fillColor);
	if (pDC->GetPixel(x - 1, y) != fillColor) BoundaryFill(pDC, x - 1, y, boundaryColor, fillColor);
	if (pDC->GetPixel(x, y + 1) != fillColor) BoundaryFill(pDC, x, y + 1, boundaryColor, fillColor);
	if (pDC->GetPixel(x, y - 1) != fillColor) BoundaryFill(pDC, x, y - 1, boundaryColor, fillColor);
}

void CFill::BoundaryFillEnhanced(CDC* pDC, int x, int y, COLORREF boundaryColor, COLORREF fillColor) {
	std::stack<std::pair<int, int>> s;
	if (pDC->GetPixel(x, y) == boundaryColor) return;
	pDC->SetPixel(x, y, fillColor);
	s.push(std::pair<int, int> {x + 1, y});
	s.push(std::pair<int, int> {x - 1, y});
	s.push(std::pair<int, int> {x, y + 1});
	s.push(std::pair<int, int> {x, y - 1});

	for (; !s.empty();) {
		std::pair<int, int> p = s.top();
		s.pop();
		x = p.first;
		y = p.second;
		COLORREF currentColor = pDC->GetPixel(x, y);
		if (currentColor == boundaryColor || currentColor == fillColor) continue;
		pDC->SetPixel(x, y, fillColor);
		if (pDC->GetPixel(x + 1, y) != fillColor) s.push(std::pair<int, int> {x + 1, y});
		if (pDC->GetPixel(x - 1, y) != fillColor) s.push(std::pair<int, int> {x - 1, y});
		if (pDC->GetPixel(x, y + 1) != fillColor) s.push(std::pair<int, int> {x, y + 1});
		if (pDC->GetPixel(x, y - 1) != fillColor) s.push(std::pair<int, int> {x, y - 1});
	}
}

#include <cmath>
#include <algorithm>

void CFill::ScanLineFill(CDC* pDC, const std::vector<int>& xs, const std::vector<int>& ys, COLORREF fillColor) {
	if (xs.size() <= 0) throw "Size of xs must be positive";
	if (xs.size() != ys.size()) throw "Size of xs and ys should be the same";
	int minY = ys[0], minYIndex = 0, maxY = ys[0], maxYIndex = 0, n = ys.size();
	for (int i = 1; i < n; i++) {
		if (minY > ys[i]) {
			minY = ys[i];
			minYIndex = i;
		}
		if (maxY < ys[i]) {
			maxY = ys[i];
			maxYIndex = i;
		}
	}

	std::vector<float> slopes, yIntercepts;
	for (int i = 0; i < n; i++) {
		int currentI = i;
		int nextI = (i + 1) % n;
		slopes.push_back((ys[currentI] - ys[nextI]) * 1.0 / (xs[currentI] - xs[nextI]));
		yIntercepts.push_back(ys[currentI] - slopes[currentI] * xs[currentI]);
	}

	for (int y = minY; y <= maxY; y++) {
		std::vector<int> intersectXs;
		for (int i = 0; i < n; i++) {
			int intersectX = round((y - yIntercepts[i]) * 1.0 / slopes[i]);
			if (min(xs[i], xs[(i + 1) % n]) <= intersectX && intersectX <= max(xs[i], xs[(i + 1) % n])) {
				intersectXs.push_back(intersectX);
			}
		}
		sort(intersectXs.begin(), intersectXs.end());

		for (int i = 0; i < intersectXs.size() + intersectXs.size() % 2; i += 2) {
			for (int x = intersectXs[i]; x <= intersectXs[i + 1]; x++) {
'

'				pDC->SetPixel(x, y, fillColor);
			}
		}
	}
}